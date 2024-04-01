object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Hotel'
  ClientHeight = 299
  ClientWidth = 308
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object LabelHotel: TLabel
    Left = 96
    Top = 32
    Width = 48
    Height = 28
    Caption = 'Hotel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelLozinka: TLabel
    Left = 48
    Top = 119
    Width = 66
    Height = 28
    Caption = 'Lozinka'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelKorisnik: TLabel
    Left = 48
    Top = 82
    Width = 70
    Height = 28
    Caption = 'Korisnik'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EditKorisnik: TEdit
    Left = 136
    Top = 82
    Width = 137
    Height = 23
    TabOrder = 0
  end
  object EditLozinka: TEdit
    Left = 136
    Top = 119
    Width = 137
    Height = 23
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 48
    Top = 176
    Width = 225
    Height = 23
    TabOrder = 2
    Text = 'Izaberi jezik'
    OnChange = ComboBox1Change
    Items.Strings = (
      'HR'
      'EN')
  end
  object ButtonReg: TButton
    Left = 64
    Top = 232
    Width = 121
    Height = 25
    Caption = 'Registriraj se'
    TabOrder = 3
    OnClick = ButtonRegClick
  end
end
