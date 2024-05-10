object FormTCPclient: TFormTCPclient
  Left = 0
  Top = 0
  Caption = 'FormTCPclient'
  ClientHeight = 344
  ClientWidth = 328
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ButtonTCP: TButton
    Left = 32
    Top = 303
    Width = 105
    Height = 33
    Caption = 'ButtonTCP'
    TabOrder = 0
    OnClick = ButtonTCPClick
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 185
    Height = 289
    TabOrder = 1
    object LabelTCPclient: TLabel
      Left = 24
      Top = 48
      Width = 121
      Height = 15
      Caption = 'Potro'#353'nja za sobe (l)'
    end
    object Label1: TLabel
      Left = 24
      Top = 101
      Width = 121
      Height = 15
      Caption = 'Potro'#353'nja za kuhinju (l)'
    end
    object Label2: TLabel
      Left = 24
      Top = 168
      Width = 124
      Height = 15
      Caption = 'Potro'#353'nja za restoran (l)'
    end
    object Label3: TLabel
      Left = 24
      Top = 232
      Width = 119
      Height = 15
      Caption = 'Potro'#353'nja za praonu (l)'
    end
    object EHost: TEdit
      Left = 24
      Top = 16
      Width = 121
      Height = 23
      TabOrder = 0
      Text = 'EHost'
    end
    object EditSoba: TEdit
      Left = 24
      Top = 69
      Width = 121
      Height = 23
      TabOrder = 1
    end
    object EditKuhinja: TEdit
      Left = 24
      Top = 122
      Width = 121
      Height = 23
      TabOrder = 2
    end
    object EditRestoran: TEdit
      Left = 24
      Top = 189
      Width = 121
      Height = 23
      TabOrder = 3
    end
    object EditPraonica: TEdit
      Left = 24
      Top = 253
      Width = 121
      Height = 23
      TabOrder = 4
    end
  end
  object IdTCPClient1: TIdTCPClient
    ConnectTimeout = 0
    Port = 15638
    ReadTimeout = -1
    Left = 224
    Top = 184
  end
end
