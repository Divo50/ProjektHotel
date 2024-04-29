object DBForm: TDBForm
  Left = 0
  Top = 0
  Caption = ' '
  ClientHeight = 808
  ClientWidth = 845
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 24
    Top = 24
    Width = 345
    Height = 161
    DataSource = DataModule1.DOdjel
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'sifOdjel'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'imeOdjela'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'brojZaposlenika'
        Width = 100
        Visible = True
      end>
  end
  object DBGrid2: TDBGrid
    Left = 24
    Top = 314
    Width = 745
    Height = 120
    DataSource = DataModule1.DZaposlenici
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'sifZaposlenik'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'imeZaposlenik'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'prezimeZaposlenik'
        Width = 110
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'datumRodjenja'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sifOdjel'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sifSmjena'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Placa'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Placa (kn)'
        Visible = True
      end>
  end
  object DBGrid3: TDBGrid
    Left = 24
    Top = 529
    Width = 433
    Height = 120
    DataSource = DataModule1.DSmjene
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'sifSmjena'
        Width = 71
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'opisSmjena'
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'vrijemeSmjena'
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'danSmjena'
        Width = 95
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 24
    Top = 191
    Width = 340
    Height = 25
    DataSource = DataModule1.DOdjel
    TabOrder = 3
  end
  object DBNavigator2: TDBNavigator
    Left = 24
    Top = 440
    Width = 720
    Height = 25
    DataSource = DataModule1.DZaposlenici
    TabOrder = 4
  end
  object DBNavigator3: TDBNavigator
    Left = 24
    Top = 655
    Width = 430
    Height = 25
    DataSource = DataModule1.DSmjene
    TabOrder = 5
  end
  object Button1: TButton
    Left = 24
    Top = 222
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 105
    Top = 222
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 24
    Top = 471
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 105
    Top = 471
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 24
    Top = 686
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 10
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 105
    Top = 686
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 11
    OnClick = Button6Click
  end
  object GroupBoxOdjel: TGroupBox
    Left = 24
    Top = 253
    Width = 249
    Height = 42
    TabOrder = 12
    object CheckBoxOdjel: TCheckBox
      Left = 10
      Top = 16
      Width = 225
      Height = 17
      Caption = 'Prika'#382'i odjele s vi'#353'e od 10 zaposlenika'
      TabOrder = 0
      OnClick = CheckBoxOdjelClick
    end
  end
  object ButtonSort: TButton
    Left = 186
    Top = 222
    Width = 183
    Height = 25
    Caption = 'Sortiraj po broju zaposlenika'
    TabOrder = 13
    OnClick = ButtonSortClick
  end
end
