Sub CodeFrame()
'
' 为代码添加框框的宏
'
'
    Selection.ConvertToTable Separator:=wdSeparateByParagraphs, NumColumns:=1, _
         NumRows:=11, AutoFitBehavior:=wdAutoFitFixed
    With Selection.Tables(1)
        .Style = "网格型"
        .ApplyStyleHeadingRows = True
        .ApplyStyleLastRow = False
        .ApplyStyleFirstColumn = True
        .ApplyStyleLastColumn = False
    End With
    Selection.InsertColumns
    
    With Selection.Tables(1).Columns(2)
        .PreferredWidthType = wdPreferredWidthPoints
        .Width = CentimetersToPoints(13.43)
        With .Shading
            .Texture = wdTextureNone
            .ForegroundPatternColor = wdColorAutomatic
            .BackgroundPatternColor = 16448250
        End With
        With .Borders(wdBorderLeft)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        With .Borders(wdBorderRight)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        With .Borders(wdBorderTop)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        With .Borders(wdBorderBottom)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        .Borders(wdBorderHorizontal).LineStyle = wdLineStyleNone
        .Borders(wdBorderDiagonalDown).LineStyle = wdLineStyleNone
        .Borders(wdBorderDiagonalUp).LineStyle = wdLineStyleNone
        .Borders.Shadow = False
    End With
    With Options
        .DefaultBorderLineStyle = wdLineStyleSingle
        .DefaultBorderLineWidth = wdLineWidth050pt
        .DefaultBorderColor = 14473169
    End With
    With Selection.Tables(1).Columns(1)
        .PreferredWidthType = wdPreferredWidthPoints
        .Width = CentimetersToPoints(1.2)
        With .Borders(wdBorderLeft)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        With .Borders(wdBorderRight)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        With .Borders(wdBorderTop)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        With .Borders(wdBorderBottom)
            .LineStyle = wdLineStyleSingle
            .LineWidth = wdLineWidth050pt
            .Color = 14473169
        End With
        .Borders(wdBorderHorizontal).LineStyle = wdLineStyleNone
        .Borders(wdBorderDiagonalDown).LineStyle = wdLineStyleNone
        .Borders(wdBorderDiagonalUp).LineStyle = wdLineStyleNone
        .Borders.Shadow = False
    End With
    With Options
        .DefaultBorderLineStyle = wdLineStyleSingle
        .DefaultBorderLineWidth = wdLineWidth050pt
        .DefaultBorderColor = 14473169
    End With
    Selection.SelectCell
    Selection.ParagraphFormat.Alignment = wdAlignParagraphRight
    Selection.Cells.VerticalAlignment = wdCellAlignVerticalTop

    ' 添加行号
    For i = 1 To Selection.Tables(1).Rows.Count
        Selection.Font.Color = 11505963
        Selection.Font.Bold = False
        Selection.Text = Str(i) + "."
        Selection.MoveDown
    Next
End Sub