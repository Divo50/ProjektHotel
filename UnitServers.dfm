object FormServers: TFormServers
  Left = 0
  Top = 0
  Caption = 'FormServers'
  ClientHeight = 291
  ClientWidth = 439
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object IdTCPServer1: TIdTCPServer
    Active = True
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 15638
      end>
    DefaultPort = 15638
    OnExecute = IdTCPServer1Execute
    Left = 296
    Top = 168
  end
  object IdUDPServer1: TIdUDPServer
    Active = True
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 19500
      end>
    DefaultPort = 19500
    OnUDPRead = IdUDPServer1UDPRead
    Left = 160
    Top = 88
  end
end
