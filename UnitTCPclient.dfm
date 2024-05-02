object FormTCPclient: TFormTCPclient
  Left = 0
  Top = 0
  Caption = 'FormTCPclient'
  ClientHeight = 242
  ClientWidth = 235
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 0
    Top = 8
    Width = 225
    Height = 177
    TabOrder = 0
    object LabelTCPclient: TLabel
      Left = 11
      Top = 16
      Width = 198
      Height = 31
      Caption = 'Broj gostiju u danu:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object EditTCPclient: TEdit
      Left = 11
      Top = 53
      Width = 65
      Height = 23
      TabOrder = 0
    end
    object ButtonTCP: TButton
      Left = 11
      Top = 82
      Width = 89
      Height = 33
      Caption = 'Po'#353'alji'
      TabOrder = 1
      OnClick = ButtonTCPClick
    end
    object EHost: TEdit
      Left = 11
      Top = 136
      Width = 121
      Height = 23
      TabOrder = 2
    end
  end
  object IdTCPClient1: TIdTCPClient
    ConnectTimeout = 0
    Port = 15638
    ReadTimeout = -1
    Left = 160
    Top = 88
  end
end
