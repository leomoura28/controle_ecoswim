import requests
import json

def lambda_handler(event, context):
    SHEET_ID = "1Q2yTsyejtbUGj0lLh8kc8iZEOJ0pX8Q5W22f1f493_4"
    raw_path = event.get('rawPath', '')

    if raw_path == '/horarios':
        url = f"https://docs.google.com/spreadsheets/d/{SHEET_ID}/gviz/tq?tqx=out:csv&sheet=HORARIOS"
        response = requests.get(url)
        dados = response.text.split('\n') if response.ok else []
        horarios = [linha.split(',') for linha in dados] 
        return {
            'statusCode': 200,
            'body': json.dumps(horarios)
        }

    elif raw_path == '/kits':
        url = f"https://docs.google.com/spreadsheets/d/{SHEET_ID}/gviz/tq?tqx=out:csv&sheet=KITSDISPONIBILIDADE"
        response = requests.get(url)
        kits = response.text.split('\n') if response.ok else []
        return {
            'statusCode': 200,
            'body': json.dumps(kits)
        }

    elif raw_path == '/equipes':
        url = f"https://docs.google.com/spreadsheets/d/{SHEET_ID}/gviz/tq?tqx=out:csv&sheet=EQUIPESFINAIS"
        response = requests.get(url)
        equipes = response.text.split('\n') if response.ok else []
        return {
            'statusCode': 200,
            'body': json.dumps(equipes)
        }

    elif raw_path == '/pagamentos':
        url = f"https://docs.google.com/spreadsheets/d/{SHEET_ID}/gviz/tq?tqx=out:csv&sheet=PAGAMENTOS"
        response = requests.get(url)
        pagamentos = response.text.split('\n') if response.ok else []
        return {
            'statusCode': 200,
            'body': json.dumps(pagamentos)
        }

    return {
        'statusCode': 404,
        'body': json.dumps({'error': 'Rota não encontrada'})
    }