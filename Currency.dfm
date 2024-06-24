object FormCur: TFormCur
  Left = 0
  Top = 0
  Caption = 'FormCur'
  ClientHeight = 433
  ClientWidth = 622
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 432
    Top = 288
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 32
    Top = 160
    Width = 361
    Height = 209
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object EditFrom: TEdit
    Left = 56
    Top = 8
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'from'
  end
  object EditTo: TEdit
    Left = 56
    Top = 56
    Width = 121
    Height = 23
    TabOrder = 3
    Text = 'to'
  end
  object EditAmount: TEdit
    Left = 56
    Top = 96
    Width = 121
    Height = 23
    TabOrder = 4
    Text = 'iznos'
  end
  object RESTClient1: TRESTClient
    Params = <>
    SynchronizedEvents = False
    Left = 176
    Top = 376
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <
      item
        Name = 'from'
      end
      item
        Name = 'to'
      end
      item
        Name = 'amount'
      end>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 240
    Top = 376
  end
  object RESTResponse1: TRESTResponse
    Left = 312
    Top = 376
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 20
    Top = 5
    object LinkControlToField1: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTRequest1
      FieldName = 'Params.amount'
      Control = EditAmount
      Track = True
    end
    object LinkControlToField2: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTRequest1
      FieldName = 'Params.to'
      Control = EditTo
      Track = True
    end
    object LinkControlToField3: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = RESTRequest1
      FieldName = 'Params.from'
      Control = EditFrom
      Track = True
    end
  end
end
