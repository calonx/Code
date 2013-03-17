
class CppWriter:
    def __init__ (self, filePath):
        self.file = open(filePath, 'w')
        self.indent = '    '
        self.currentIndent = ''
        self.indentLevel = 0
    
    def Close (self):
        self.file.close()
    
    def Indent (self):
        ++self.indentLevel
        self.currentIndent += self.indent
    
    def Dedent (self):
        --self.indentLevel
        indentCharCount = len(self.indent)
        self.currentIndent = self.currentIndent[:-indentCharCount]
    
    def Write (self, value):
        self.file.write(value)
    
    def WriteIndented (self, value = ""):
        self.file.write(self.currentIndent + value)
    
    def WriteLine (self, value = ""):
        self.file.write(value + "\n")
    
    def WriteLineIndented (self, value = ""):
        self.file.write(self.currentIndent + value + "\n")
    
    def WriteSectionComment (self, comment):
        indentChars = self.indentLevel * len(self.indent)
        dividerLength = 80 - indentChars
        divider = "//=============================================================================="[:dividerLength]
        self.WriteLine()
        self.WriteLine()
        self.WriteLineIndented(divider)
        self.WriteLineIndented("// " + comment)
        self.WriteLineIndented(divider)


class StructScope:
    def __init__ (self, writer, name):
        self.writer = writer
        self.writer.WriteLineIndented("struct %s {" % name)
        self.writer.Indent()
    
    def Close (self):
        self.writer.Dedent()
        self.writer.WriteLineIndented("};")


class GeneratedType:
    def __init__ (self, name, type, fields):
        self.name = name
        self.type = type
        self.fields = fields.split(',')
    
    def WriteDeclaration (self, writer):
        scope = StructScope(writer, self.name)
        for field in self.fields:
            writer.WriteLineIndented("%s %s;" % (self.type, field))
        
        # Write constructor
        writer.WriteLine()
        writer.WriteLineIndented("inline %s () { }" % self.name)
        
        # Write copy-constructor
        writer.WriteLine()
        writer.WriteLineIndented("inline %s (const %s & rhs) {" % (self.name, self.name))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented("this->%s = rhs.%s;" % (field, field))
        writer.Dedent()
        writer.WriteLineIndented("}")
        
        # Write component-constructor
        writer.WriteLine()
        writer.WriteIndented("inline %s (" % self.name)
        writer.Write(', '.join(["%s %s" % (self.type, x) for x in self.fields]))
        writer.WriteLine(") {")
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented("this->%s = %s;" % (field, field))
        writer.Dedent()
        writer.WriteLineIndented("};")
        
        # Write single-component constructor
        writer.WriteLine()
        writer.WriteLineIndented("inline %s (%s v) {" % (self.name, self.type))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented("this->%s = v;" % field)
        writer.Dedent()
        writer.WriteLineIndented("};")
        
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented("inline const %s & operator = (const %s & rhs) {" % (self.name, self.name))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented("this->%s = rhs.%s;" % (field, field))
        writer.WriteLineIndented("return *this;");
        writer.Dedent()
        writer.WriteLineIndented("}")
        
        self.WriteOpEqualsComponent(writer, "+=");
        self.WriteOpEqualsComponent(writer, "-=");
        self.WriteOpEqualsComponent(writer, "*=");
        self.WriteOpEqualsComponent(writer, "/=");
        
        self.WriteOpEqualsSingle(writer, "+=");
        self.WriteOpEqualsSingle(writer, "-=");
        self.WriteOpEqualsSingle(writer, "*=");
        self.WriteOpEqualsSingle(writer, "/=");
        
        self.WriteOpStaticComponent(writer, "+");
        self.WriteOpStaticComponent(writer, "-");
        self.WriteOpStaticComponent(writer, "*");
        self.WriteOpStaticComponent(writer, "/");
        
        self.WriteOpStaticSingle(writer, "+");
        self.WriteOpStaticSingle(writer, "-");
        self.WriteOpStaticSingle(writer, "*");
        self.WriteOpStaticSingle(writer, "/");
        
        scope.Close()
        
        writer.WriteLine()
        writer.WriteLine()
    
    def WriteOpEqualsComponent (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented("inline const %s & operator %s (const %s & rhs) {" % (self.name, op, self.name))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented("this->%s %s rhs.%s;" % (field, op, field))
        writer.WriteLineIndented("return *this;");
        writer.Dedent()
        writer.WriteLineIndented("}")
    
    def WriteOpEqualsSingle (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented("inline const %s & operator %s (%s s) {" % (self.name, op, self.type))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented("this->%s %s s;" % (field, op))
        writer.WriteLineIndented("return *this;");
        writer.Dedent()
        writer.WriteLineIndented("}")
    
    def WriteOpStaticComponent (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented("inline static {name} operator {op} (const {name} & lhs, const {name} & rhs) {{".format(name=self.name, op=op))
        writer.Indent()
        
        expressions = ["lhs.{field} {op} rhs.{field}".format(field=field, op=op) for field in self.fields]
        writer.WriteLineIndented("return {name}({expr});".format(name=self.name, expr=", ".join(expressions)))
        
        writer.Dedent()
        writer.WriteLineIndented("}")
    
    def WriteOpStaticSingle (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented("inline static {name} operator {op} (const {name} & lhs, {type} s) {{".format(name=self.name, op=op, type=self.type))
        writer.Indent()
        
        expressions = ["lhs.{field} {op} s".format(field=field, op=op) for field in self.fields]
        writer.WriteLineIndented("return {name}({expr});".format(name=self.name, expr=", ".join(expressions)))
        
        writer.Dedent()
        writer.WriteLineIndented("}")
    
    def WriteMathMagnitudeSq (self, writer):
        writer.WriteLine()
        writer.WriteLineIndented("{type} MathMagnitudeSq (const {name} & v) {{".format(name=self.name, type=self.type))
        writer.Indent()
        
        expressions = ["v.{0} * v.{0}".format(field) for field in self.fields]
        writer.WriteLineIndented("return " + " + ".join(expressions) + ";")
        
        writer.Dedent()
        writer.WriteLineIndented("}")
    
    def WriteMathMagnitude (self, writer):
        writer.WriteLine()
        writer.WriteLineIndented("{type} MathMagnitude (const {name} & v) {{".format(name=self.name, type=self.type))
        writer.Indent()
        
        expressions = ["v.{0} * v.{0}".format(field) for field in self.fields]
        writer.WriteLineIndented("return MathSqrt(" + " + ".join(expressions) + ");")
        
        writer.Dedent()
        writer.WriteLineIndented("}")
    
    def WriteMathDotProduct (self, writer):
        writer.WriteLine()
        writer.WriteLineIndented("{type} MathDotProduct (const {name} & lhs, const {name} & rhs) {{".format(name=self.name, type=self.type))
        writer.Indent()
        
        expressions = ["lhs.{0} * rhs.{0}".format(field) for field in self.fields]
        writer.WriteLineIndented("return " + " + ".join(expressions) + ";")
        
        writer.Dedent()
        writer.WriteLineIndented("}")


class MathCommon:
    def WriteAll (types, writer):
        writer.WriteSectionComment("MathMagnitudeSq")
        for type in types:
            type.WriteMathMagnitudeSq(writer)

        writer.WriteSectionComment("MathMagnitude")
        for type in types:
            type.WriteMathMagnitude(writer)

        writer.WriteSectionComment("MathDotProduct")
        for type in types:
            type.WriteMathDotProduct(writer)
        
        writer.WriteSectionComment("Normalization")
        MathCommon.WriteMathNormalizeInPlace(writer)
        MathCommon.WriteMathNormalize(writer)
    
    def WriteMathNormalizeInPlace (writer):
        writer.WriteLine()
        writer.WriteLineIndented("template<class T>")
        writer.WriteLineIndented("void MathNormalize (T * t) {")
        writer.Indent()
        writer.WriteLineIndented("*t = *t / MathMagnitude(*t);")
        writer.Dedent()
        writer.WriteLineIndented("}");
    
    def WriteMathNormalize (writer):
        writer.WriteLine()
        writer.WriteLineIndented("template<class T>")
        writer.WriteLineIndented("void MathNormalize (const T & src, T * dst) {")
        writer.Indent()
        writer.WriteLineIndented("*dst = src / MathMagnitude(src);")
        writer.Dedent()
        writer.WriteLineIndented("}");


types = [
    GeneratedType("Vec2f",   "float",    "x,y"),
    GeneratedType("Vec3f",   "float",    "x,y,z"),
    GeneratedType("Vec4f",   "float",    "x,y,z,w"),
    GeneratedType("Vec2d",   "double",   "x,y"),
    GeneratedType("Vec3d",   "double",   "x,y,z"),
    GeneratedType("Vec4d",   "double",   "x,y,z,w"),
    GeneratedType("Vec2i",   "int",      "x,y"),
    GeneratedType("Vec3i",   "int",      "x,y,z"),
    GeneratedType("Vec4i",   "int",      "x,y,z,w"),
    GeneratedType("Vec2u",   "unsigned", "x,y"),
    GeneratedType("Vec3u",   "unsigned", "x,y,z"),
    GeneratedType("Vec4u",   "unsigned", "x,y,z,w"),
    GeneratedType("Color4f", "float",    "r,g,b,a"),
    GeneratedType("Color4b", "byte",     "r,g,b,a"),
]

declWriter = CppWriter('Types.h')
for type in types:
    type.WriteDeclaration(declWriter)
declWriter.Close()

mathWriter = CppWriter('Math.h')
MathCommon.WriteAll(types, mathWriter)
mathWriter.Close()
