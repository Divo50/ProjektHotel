object DBForm: TDBForm
  Left = 0
  Top = 0
  Caption = ' '
  ClientHeight = 686
  ClientWidth = 1070
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
    DataSource = DOdjel
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
    Left = 448
    Top = 56
    Width = 569
    Height = 120
    DataSource = DZaposlenici
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
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'imeZaposlenik'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'prezimeZaposlenik'
        Width = 108
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'datumRodjenja'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sifOdjel'
        Width = 60
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'sifSmjena'
        Width = 62
        Visible = True
      end>
  end
  object DBGrid3: TDBGrid
    Left = 256
    Top = 392
    Width = 433
    Height = 120
    DataSource = DSmjene
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
    Top = 216
    Width = 340
    Height = 25
    DataSource = DOdjel
    TabOrder = 3
  end
  object DBNavigator2: TDBNavigator
    Left = 448
    Top = 192
    Width = 560
    Height = 25
    DataSource = DZaposlenici
    TabOrder = 4
  end
  object DBNavigator3: TDBNavigator
    Left = 256
    Top = 536
    Width = 430
    Height = 25
    DataSource = DSmjene
    TabOrder = 5
  end
  object Button1: TButton
    Left = 88
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 216
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 640
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 784
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 344
    Top = 584
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 10
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 504
    Top = 584
    Width = 75
    Height = 25
    Caption = 'Obri'#353'i'
    TabOrder = 11
    OnClick = Button6Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=bazapod.mdb;Persist' +
      ' Security Info=False'
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 72
    Top = 24
  end
  object TOdjel: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'odjel'
    Left = 168
    Top = 32
  end
  object TSmjene: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    IndexFieldNames = 'sifSmjena'
    MasterFields = 'sifSmjena'
    MasterSource = DZaposlenici
    TableName = 'smjene'
    Left = 344
    Top = 32
  end
  object TZaposlenici: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    IndexFieldNames = 'sifOdjel'
    MasterFields = 'sifOdjel'
    MasterSource = DOdjel
    TableName = 'zaposlenici'
    Left = 248
    Top = 32
  end
  object DOdjel: TDataSource
    DataSet = TOdjel
    Left = 168
    Top = 96
  end
  object DSmjene: TDataSource
    DataSet = TSmjene
    Left = 344
    Top = 96
  end
  object DZaposlenici: TDataSource
    DataSet = TZaposlenici
    Left = 248
    Top = 96
  end
end
