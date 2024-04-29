object DataModule1: TDataModule1
  Height = 311
  Width = 417
  PixelsPerInch = 120
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\Win11\Docu' +
      'ments\Desktop\hoteli\bazapod.mdb;Persist Security Info=False'
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 48
    Top = 116
  end
  object TOdjel: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'odjel'
    Left = 120
    Top = 68
    object TOdjelsifOdjel: TAutoIncField
      FieldName = 'sifOdjel'
      ReadOnly = True
    end
    object TOdjelimeOdjela: TWideStringField
      FieldName = 'imeOdjela'
      Size = 255
    end
    object TOdjelbrojZaposlenika: TWideStringField
      FieldName = 'brojZaposlenika'
      Size = 255
    end
  end
  object TSmjene: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    IndexFieldNames = 'sifSmjena'
    MasterFields = 'sifSmjena'
    MasterSource = DZaposlenici
    TableName = 'smjene'
    Left = 280
    Top = 76
    object TSmjenesifSmjena: TAutoIncField
      FieldName = 'sifSmjena'
      ReadOnly = True
    end
    object TSmjeneopisSmjena: TWideStringField
      FieldName = 'opisSmjena'
      Size = 255
    end
    object TSmjenevrijemeSmjena: TDateTimeField
      FieldName = 'vrijemeSmjena'
    end
    object TSmjenedanSmjena: TWideStringField
      FieldName = 'danSmjena'
      Size = 255
    end
  end
  object TZaposlenici: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    OnCalcFields = TZaposleniciCalcFields
    IndexFieldNames = 'sifOdjel'
    MasterFields = 'sifOdjel'
    MasterSource = DOdjel
    TableName = 'zaposlenici'
    Left = 208
    Top = 68
    object TZaposlenicisifZaposlenik: TAutoIncField
      FieldName = 'sifZaposlenik'
      ReadOnly = True
    end
    object TZaposleniciimeZaposlenik: TWideStringField
      FieldName = 'imeZaposlenik'
      Size = 255
    end
    object TZaposleniciprezimeZaposlenik: TWideStringField
      FieldName = 'prezimeZaposlenik'
      Size = 255
    end
    object TZaposlenicidatumRodjenja: TDateTimeField
      FieldName = 'datumRodjenja'
    end
    object TZaposlenicisifOdjel: TIntegerField
      FieldName = 'sifOdjel'
    end
    object TZaposlenicisifSmjena: TIntegerField
      FieldName = 'sifSmjena'
    end
    object TZaposleniciPlaca: TBCDField
      FieldName = 'Placa'
      Precision = 19
    end
    object TZaposleniciPlacakn: TCurrencyField
      FieldKind = fkCalculated
      FieldName = 'Placa (kn)'
      Calculated = True
    end
  end
  object DOdjel: TDataSource
    DataSet = TOdjel
    Left = 112
    Top = 164
  end
  object DSmjene: TDataSource
    DataSet = TSmjene
    Left = 272
    Top = 172
  end
  object DZaposlenici: TDataSource
    DataSet = TZaposlenici
    Left = 200
    Top = 172
  end
end
