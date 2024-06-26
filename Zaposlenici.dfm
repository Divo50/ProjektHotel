object FormZaposlenici: TFormZaposlenici
  Left = 0
  Top = 0
  Caption = 'Zaposlenici'
  ClientHeight = 584
  ClientWidth = 612
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object LabelZaposlenik: TLabel
    Left = 8
    Top = 559
    Width = 48
    Height = 15
    Alignment = taCenter
    Caption = 'Korisnik: '
  end
  object GroupBox2: TGroupBox
    Left = 328
    Top = 8
    Width = 296
    Height = 105
    Caption = 'Zaposlenici'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 8
    Width = 289
    Height = 105
    BiDiMode = bdLeftToRight
    Caption = 'Sobe i pi'#263'a'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Verdana'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    TabOrder = 6
  end
  object Button1Sobe: TButton
    Left = 8
    Top = 42
    Width = 113
    Height = 45
    Caption = 'Sobe - XML'
    TabOrder = 0
    OnClick = Button1SobeClick
  end
  object Button2Pica: TButton
    Left = 152
    Top = 42
    Width = 114
    Height = 45
    Caption = 'Pi'#263'a - JSON'
    TabOrder = 1
    OnClick = Button2PicaClick
  end
  object ButtonZ: TButton
    Left = 376
    Top = 42
    Width = 188
    Height = 45
    Caption = 'Zaposlenici u hotelu - baze'
    TabOrder = 2
    OnClick = ButtonZClick
  end
  object ButtonTCP: TButton
    Left = 0
    Top = 476
    Width = 114
    Height = 45
    Caption = 'Ra'#269'un za vodu'
    TabOrder = 3
    OnClick = ButtonTCPClick
  end
  object ButtonUDP: TButton
    Left = 120
    Top = 476
    Width = 104
    Height = 45
    Caption = 'Godisnji odmor'
    TabOrder = 4
    OnClick = ButtonUDPClick
  end
  object Button7: TButton
    Left = 479
    Top = 476
    Width = 131
    Height = 45
    Caption = 'Izra'#269'un temperature'
    TabOrder = 5
    OnClick = Button7Click
  end
  object ButtonCurrency: TButton
    Left = 473
    Top = 119
    Width = 139
    Height = 45
    Caption = 'Currency'
    TabOrder = 8
    OnClick = ButtonCurrencyClick
  end
  object ButtonCjenik: TButton
    Left = 24
    Top = 234
    Width = 113
    Height = 45
    Caption = 'Preuzmi cjenik'
    TabOrder = 9
    OnClick = ButtonCjenikClick
  end
  object Button10: TButton
    Left = 473
    Top = 254
    Width = 129
    Height = 25
    Caption = 'DLL - Bicikli'
    TabOrder = 10
    OnClick = Button10Click
  end
  object BHRV: TButton
    Left = 416
    Top = 552
    Width = 75
    Height = 25
    Caption = 'HRV'
    TabOrder = 11
    OnClick = BHRVClick
  end
  object BENG: TButton
    Left = 497
    Top = 552
    Width = 75
    Height = 25
    Caption = 'ENG'
    TabOrder = 12
    OnClick = BENGClick
  end
end
