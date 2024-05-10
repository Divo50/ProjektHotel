object FormJSON: TFormJSON
  Left = 0
  Top = 0
  Caption = 'FormJSON'
  ClientHeight = 307
  ClientWidth = 737
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ListViewJSON: TListView
    Left = 8
    Top = 8
    Width = 337
    Height = 289
    Columns = <
      item
        Caption = 'Ime'
      end
      item
        Caption = 'Vrsta'
      end
      item
        Caption = 'Godina proizvodnje'
      end
      item
        Caption = 'Alkohol'
      end
      item
        Caption = 'Dr'#382'ava'
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
  end
  object GumbUcitajJSON: TButton
    Left = 376
    Top = 19
    Width = 105
    Height = 33
    Caption = 'U'#269'itaj'
    TabOrder = 1
    OnClick = GumbUcitajJSONClick
  end
  object GumbDodajJSON: TButton
    Left = 376
    Top = 66
    Width = 105
    Height = 33
    Caption = 'Dodaj'
    TabOrder = 2
    OnClick = GumbDodajJSONClick
  end
  object GumbUpdateJSON: TButton
    Left = 376
    Top = 115
    Width = 105
    Height = 33
    Caption = 'A'#382'uriraj'
    TabOrder = 3
    OnClick = GumbUpdateJSONClick
  end
  object GumbBrisiJSON: TButton
    Left = 376
    Top = 163
    Width = 105
    Height = 33
    Caption = 'Izbri'#353'i'
    TabOrder = 4
    OnClick = GumbBrisiJSONClick
  end
  object GumbSpremiJSON: TButton
    Left = 376
    Top = 219
    Width = 105
    Height = 33
    Caption = 'Spremi promjenu'
    TabOrder = 5
    OnClick = GumbSpremiJSONClick
  end
  object GroupBoxDodaj: TGroupBox
    Left = 528
    Top = 8
    Width = 201
    Height = 289
    Caption = 'Dodaj novo pi'#263'e'
    TabOrder = 6
    object EditAlkohoJSON: TEdit
      Left = 16
      Top = 200
      Width = 169
      Height = 25
      TabOrder = 0
    end
    object EditVrstaJSON: TEdit
      Left = 16
      Top = 96
      Width = 169
      Height = 23
      TabOrder = 1
    end
    object EditGodinaJSON: TEdit
      Left = 16
      Top = 155
      Width = 169
      Height = 23
      TabOrder = 2
    end
    object EditDrzavaJSON: TEdit
      Left = 16
      Top = 248
      Width = 169
      Height = 25
      TabOrder = 3
    end
    object EditImeJSON: TEdit
      Left = 16
      Top = 48
      Width = 169
      Height = 23
      TabOrder = 4
    end
  end
end
