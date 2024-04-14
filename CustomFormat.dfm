object FormCustom: TFormCustom
  Left = 0
  Top = 0
  Caption = 'FormCustom'
  ClientHeight = 129
  ClientWidth = 463
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object GumbSpremi: TButton
    Left = 104
    Top = 48
    Width = 75
    Height = 25
    Caption = 'GumbSpremi'
    TabOrder = 0
    OnClick = GumbSpremiClick
  end
  object GumbOtvori: TButton
    Left = 248
    Top = 48
    Width = 75
    Height = 25
    Caption = 'GumbOtvori'
    TabOrder = 1
    OnClick = GumbOtvoriClick
  end
end
