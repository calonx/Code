Imports System
Imports EnvDTE
Imports EnvDTE80
Imports EnvDTE90
Imports System.Diagnostics

Public Module PaulMacros
    Sub AddFunctionHeader()
        DTE.UndoContext.Open("Add Function Header")
        Dim selection As TextSelection = DTE.ActiveDocument.Selection
        selection.StartOfLine(vsStartOfLineOptions.vsStartOfLineOptionsFirstText)
        selection.Text = "//=============================================================================="
        selection.NewLine()
        DTE.UndoContext.Close()
    End Sub

    Sub AddFileHeader()
        DTE.UndoContext.Open("Add File Header")
        Dim selection As TextSelection = DTE.ActiveDocument.Selection
        selection.StartOfDocument()
        selection.Text = "//=============================================================================="
        selection.NewLine()
        selection.Insert("// " + DTE.ActiveDocument.Name)
        selection.NewLine()
        selection.Insert("// Paul Marden (" + FormatDateTime(Date.Today, DateFormat.ShortDate) + ")")
        selection.NewLine()
        selection.Text = "//=============================================================================="
        selection.NewLine()
        DTE.UndoContext.Close()
    End Sub

    Sub AddSectionHeader()
        DTE.UndoContext.Open("Add Section Header")
        Dim selection As TextSelection = DTE.ActiveDocument.Selection
        selection.StartOfLine(vsStartOfLineOptions.vsStartOfLineOptionsFirstText)
        selection.Text = "//=============================================================================="
        selection.NewLine()
        selection.Insert("// ")
        selection.NewLine()
        selection.Text = "//=============================================================================="
        selection.NewLine()
        selection.LineUp()
        selection.LineUp()
        selection.WordRight()
        DTE.UndoContext.Close()
    End Sub
End Module

