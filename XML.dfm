object FormXML: TFormXML
  Left = 0
  Top = 0
  Caption = 'FormXML'
  ClientHeight = 640
  ClientWidth = 499
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ListViewXML: TListView
    Left = 8
    Top = 8
    Width = 313
    Height = 233
    Columns = <
      item
        Caption = 'Soba'
      end
      item
        Caption = 'Ime'
      end
      item
        Caption = 'Prezime'
      end
      item
        Caption = 'Kreveti'
      end
      item
        Caption = 'Cijena'
      end
      item
        Caption = 'Balkon'
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
  end
  object GumbUcitajXML: TButton
    Left = 336
    Top = 8
    Width = 105
    Height = 33
    Caption = 'U'#269'itaj'
    TabOrder = 1
    OnClick = GumbUcitajXMLClick
  end
  object GumbDodajXML: TButton
    Left = 336
    Top = 55
    Width = 105
    Height = 33
    Caption = 'Dodaj'
    TabOrder = 2
    OnClick = GumbDodajXMLClick
  end
  object GroupBoxDodaj: TGroupBox
    Left = 8
    Top = 247
    Width = 201
    Height = 259
    Caption = 'Dodaj Informacije o sobi'
    TabOrder = 3
    object EditBalkon: TEdit
      Left = 16
      Top = 223
      Width = 169
      Height = 23
      TabOrder = 0
    end
    object EditCijena: TEdit
      Left = 16
      Top = 186
      Width = 169
      Height = 23
      TabOrder = 1
    end
    object EditIme: TEdit
      Left = 16
      Top = 72
      Width = 169
      Height = 23
      TabOrder = 2
    end
    object EditKrevet: TEdit
      Left = 16
      Top = 144
      Width = 169
      Height = 23
      TabOrder = 3
    end
    object EditPrezime: TEdit
      Left = 16
      Top = 109
      Width = 169
      Height = 23
      TabOrder = 4
    end
    object EditSoba: TEdit
      Left = 16
      Top = 32
      Width = 169
      Height = 23
      TabOrder = 5
    end
  end
  object GumbSaveXML: TButton
    Left = 336
    Top = 104
    Width = 105
    Height = 33
    Caption = 'Spremi promjenu'
    TabOrder = 4
    OnClick = GumbSaveXMLClick
  end
  object GumbBrisiXML: TButton
    Left = 336
    Top = 152
    Width = 105
    Height = 33
    Caption = 'Izbri'#353'i'
    TabOrder = 5
    OnClick = GumbBrisiXMLClick
  end
  object XMLDocument1: TXMLDocument
    FileName = 'C:\Users\Win11\Documents\Desktop\hoteli\podatci.xml'
    NodeIndentStr = '    '
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl]
    Left = 392
    Top = 288
  end
end
