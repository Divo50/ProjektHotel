object FormUDPClient: TFormUDPClient
  Left = 0
  Top = 0
  Caption = 'FormUDPClient'
  ClientHeight = 183
  ClientWidth = 264
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 43
    Width = 105
    Height = 15
    Caption = 'Unesite broj gostiju:'
  end
  object EditPoruka: TEdit
    Left = 24
    Top = 64
    Width = 145
    Height = 23
    TabOrder = 0
  end
  object ButtonUDP: TButton
    Left = 24
    Top = 104
    Width = 75
    Height = 25
    Caption = 'ButtonUDP'
    TabOrder = 1
    OnClick = ButtonUDPClick
  end
  object EHost: TEdit
    Left = 24
    Top = 8
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'EHost'
  end
  object IdUDPClient1: TIdUDPClient
    Port = 19500
    Left = 200
    Top = 104
  end
end
