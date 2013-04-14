
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
    
    def WriteIndented (self, value = ''):
        self.file.write(self.currentIndent + value)
    
    def WriteLine (self, value = ''):
        self.file.write(value + '\n')
    
    def WriteLineIndented (self, value = ''):
        self.file.write(self.currentIndent + value + '\n')
    
    def WriteSectionComment (self, comment):
        indentChars = self.indentLevel * len(self.indent)
        dividerLength = 80 - indentChars
        divider = '//=============================================================================='[:dividerLength]
        self.WriteLine()
        self.WriteLineIndented(divider)
        self.WriteLineIndented('// ' + comment)
        self.WriteLineIndented(divider)
        self.WriteLine()


class StructScope:
    def __init__ (self, writer, name):
        self.writer = writer
        self.writer.WriteLineIndented('struct %s {' % name)
        self.writer.Indent()
    
    def Close (self):
        self.writer.Dedent()
        self.writer.WriteLineIndented('};')


class GeneratedType:
    def __init__ (self, name, type, fields):
        self.name = name
        self.type = type
        self.fields = fields.split(',')
    
    def WriteDeclaration (self, writer):
        declWriter.WriteSectionComment(self.name)
        scope = StructScope(writer, self.name)
        for field in self.fields:
            writer.WriteLineIndented('%s %s;' % (self.type, field))
        
        # Write constructor
        writer.WriteLine()
        writer.WriteLineIndented('inline %s () {' % self.name)
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented('this->%s = 0;' % field)
        writer.Dedent()
        writer.WriteLineIndented('}')
        
        # Write copy-constructor
        writer.WriteLine()
        writer.WriteLineIndented('inline %s (const %s & rhs) {' % (self.name, self.name))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented('this->%s = rhs.%s;' % (field, field))
        writer.Dedent()
        writer.WriteLineIndented('}')
        
        # Write component-constructor
        writer.WriteLine()
        writer.WriteIndented('inline %s (' % self.name)
        writer.Write(', '.join(['%s %s' % (self.type, x) for x in self.fields]))
        writer.WriteLine(') {')
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented('this->%s = %s;' % (field, field))
        writer.Dedent()
        writer.WriteLineIndented('};')
        
        # Write single-component constructor
        writer.WriteLine()
        writer.WriteLineIndented('inline %s (%s v) {' % (self.name, self.type))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented('this->%s = v;' % field)
        writer.Dedent()
        writer.WriteLineIndented('};')
        
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented('inline const %s & operator = (const %s & rhs) {' % (self.name, self.name))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented('this->%s = rhs.%s;' % (field, field))
        writer.WriteLineIndented('return *this;');
        writer.Dedent()
        writer.WriteLineIndented('}')
        
        self.WriteOpEqualsComponent(writer, '+=');
        self.WriteOpEqualsComponent(writer, '-=');
        self.WriteOpEqualsComponent(writer, '*=');
        self.WriteOpEqualsComponent(writer, '/=');
        
        self.WriteOpEqualsSingle(writer, '+=');
        self.WriteOpEqualsSingle(writer, '-=');
        self.WriteOpEqualsSingle(writer, '*=');
        self.WriteOpEqualsSingle(writer, '/=');
        
        scope.Close()
        
        self.WriteOpStaticComponent(writer, '+');
        self.WriteOpStaticComponent(writer, '-');
        self.WriteOpStaticComponent(writer, '*');
        self.WriteOpStaticComponent(writer, '/');
        
        self.WriteOpStaticSingle(writer, '+');
        self.WriteOpStaticSingle(writer, '-');
        self.WriteOpStaticSingle(writer, '*');
        self.WriteOpStaticSingle(writer, '/');
        
        writer.WriteLine()
        writer.WriteLine()
    
    def WriteOpEqualsComponent (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented('inline const %s & operator %s (const %s & rhs) {' % (self.name, op, self.name))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented('this->%s %s rhs.%s;' % (field, op, field))
        writer.WriteLineIndented('return *this;');
        writer.Dedent()
        writer.WriteLineIndented('}')
    
    def WriteOpEqualsSingle (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented('inline const %s & operator %s (%s s) {' % (self.name, op, self.type))
        writer.Indent()
        for field in self.fields:
            writer.WriteLineIndented('this->%s %s s;' % (field, op))
        writer.WriteLineIndented('return *this;');
        writer.Dedent()
        writer.WriteLineIndented('}')
    
    def WriteOpStaticComponent (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented('inline static {name} operator {op} (const {name} & lhs, const {name} & rhs) {{'.format(name=self.name, op=op))
        writer.Indent()
        
        expressions = ['lhs.{field} {op} rhs.{field}'.format(field=field, op=op) for field in self.fields]
        writer.WriteLineIndented('return {name}({expr});'.format(name=self.name, expr=', '.join(expressions)))
        
        writer.Dedent()
        writer.WriteLineIndented('}')
    
    def WriteOpStaticSingle (self, writer, op):
        # Write assignment-operator
        writer.WriteLine()
        writer.WriteLineIndented('inline static {name} operator {op} (const {name} & lhs, {type} s) {{'.format(name=self.name, op=op, type=self.type))
        writer.Indent()
        
        expressions = ['lhs.{field} {op} s'.format(field=field, op=op) for field in self.fields]
        writer.WriteLineIndented('return {name}({expr});'.format(name=self.name, expr=', '.join(expressions)))
        
        writer.Dedent()
        writer.WriteLineIndented('}')
    
    def WriteMathMagSq (self, writer):
        writer.WriteLine()
        writer.WriteLineIndented('{type} MagSq (const {name} & v) {{'.format(name=self.name, type=self.type))
        writer.Indent()
        
        expressions = ['v.{0} * v.{0}'.format(field) for field in self.fields]
        writer.WriteLineIndented('return ' + ' + '.join(expressions) + ';')
        
        writer.Dedent()
        writer.WriteLineIndented('}')
    
    def WriteMathMag (self, writer):
        writer.WriteLine()
        writer.WriteLineIndented('{type} Mag (const {name} & v) {{'.format(name=self.name, type=self.type))
        writer.Indent()
        
        expressions = ['v.{0} * v.{0}'.format(field) for field in self.fields]
        writer.WriteLineIndented('return Sqrt(' + ' + '.join(expressions) + ');')
        
        writer.Dedent()
        writer.WriteLineIndented('}')
    
    def WriteMathDotProduct (self, writer):
        writer.WriteLine()
        writer.WriteLineIndented('{type} Dot (const {name} & lhs, const {name} & rhs) {{'.format(name=self.name, type=self.type))
        writer.Indent()
        
        expressions = ['lhs.{0} * rhs.{0}'.format(field) for field in self.fields]
        writer.WriteLineIndented('return ' + ' + '.join(expressions) + ';')
        
        writer.Dedent()
        writer.WriteLineIndented('}')


class MathCommon:
    def WriteAll (types, writer):
        writer.WriteLine('namespace Math')
        writer.WriteLine('{')

        writer.WriteSectionComment('Common functions')
        MathCommon.WriteMathFunction(writer, 'Sqrt', 'f32')
        MathCommon.WriteMathFunction(writer, 'Sqrt', 'f64')
        MathCommon.WriteMathFunction(writer, 'Cos', 'f32')
        MathCommon.WriteMathFunction(writer, 'Cos', 'f64')
        MathCommon.WriteMathFunction(writer, 'Sin', 'f32')
        MathCommon.WriteMathFunction(writer, 'Sin', 'f64')
        MathCommon.WriteMathFunction(writer, 'Tan', 'f32')
        MathCommon.WriteMathFunction(writer, 'Tan', 'f64')
        MathCommon.WriteMathFunction(writer, 'Acos', 'f32')
        MathCommon.WriteMathFunction(writer, 'Acos', 'f64')
        MathCommon.WriteMathFunction(writer, 'Asin', 'f32')
        MathCommon.WriteMathFunction(writer, 'Asin', 'f64')

        writer.WriteSectionComment('MagSq')
        for type in types:
            type.WriteMathMagSq(writer)

        writer.WriteSectionComment('Mag')
        for type in types:
            if type.type == 'f32' or type == 'f64':
                type.WriteMathMag(writer)

        writer.WriteSectionComment('Dot')
        for type in types:
            type.WriteMathDotProduct(writer)
        
        writer.WriteSectionComment('Normalization')
        MathCommon.WriteMathNormalizeInPlace(writer)
        MathCommon.WriteMathNormalize(writer)
        MathCommon.WriteMathNormalized(writer)

        writer.WriteLine()
        writer.WriteLine('} // namespace Math')

    def WriteMathFunction (writer, function, type):
        args = { 'type':type, 'func':function, 'funcLib':function.lower() }
        writer.WriteLine()
        writer.WriteLineIndented('inline {type} {func} ({type} v) {{'.format(**args))
        writer.Indent()
        writer.WriteLineIndented('return {type}({funcLib}(v));'.format(**args))
        writer.Dedent()
        writer.WriteLineIndented('}');
    
    def WriteMathNormalizeInPlace (writer):
        writer.WriteLine()
        writer.WriteLineIndented('template<class T>')
        writer.WriteLineIndented('void Normalize (T * t) {')
        writer.Indent()
        writer.WriteLineIndented('*t = *t / Mag(*t);')
        writer.Dedent()
        writer.WriteLineIndented('}');
    
    def WriteMathNormalize (writer):
        writer.WriteLine()
        writer.WriteLineIndented('template<class T>')
        writer.WriteLineIndented('void Normalize (const T & src, T * dst) {')
        writer.Indent()
        writer.WriteLineIndented('*dst = src / Mag(src);')
        writer.Dedent()
        writer.WriteLineIndented('}');

    def WriteMathNormalized (writer):
        writer.WriteLine()
        writer.WriteLineIndented('template<class T>')
        writer.WriteLineIndented('const T & Normalized (T * src) {')
        writer.Indent()
        writer.WriteLineIndented('*src /= Mag(src);')
        writer.WriteLineIndented('return *src;')
        writer.Dedent()
        writer.WriteLineIndented('}');


types = [
    GeneratedType('Vec2f',   'f32', 'x,y'),
    GeneratedType('Vec3f',   'f32', 'x,y,z'),
    GeneratedType('Vec4f',   'f32', 'x,y,z,w'),
    GeneratedType('Vec2d',   'f64', 'x,y'),
    GeneratedType('Vec3d',   'f64', 'x,y,z'),
    GeneratedType('Vec4d',   'f64', 'x,y,z,w'),
    GeneratedType('Vec2i',   's32', 'x,y'),
    GeneratedType('Vec3i',   's32', 'x,y,z'),
    GeneratedType('Vec4i',   's32', 'x,y,z,w'),
    GeneratedType('Vec2u',   'u32', 'x,y'),
    GeneratedType('Vec3u',   'u32', 'x,y,z'),
    GeneratedType('Vec4u',   'u32', 'x,y,z,w'),
    GeneratedType('Color4f', 'f32', 'r,g,b,a'),
    GeneratedType('Color4b', 'u8',  'r,g,b,a'),
]

declWriter = CppWriter('Types.h')

declWriter.WriteSectionComment('Typedefs')
declWriter.WriteLine('''
typedef char                s8;
typedef short               s16;
typedef int                 s32;
typedef __int64             s64;

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned __int64    u64;

typedef float               f32;
typedef double              f64;

typedef wchar_t             wchar;''')

declWriter.WriteLine()
for type in types:
    type.WriteDeclaration(declWriter)
declWriter.Close()

mathWriter = CppWriter('Math.h')
MathCommon.WriteAll(types, mathWriter)
mathWriter.Close()
