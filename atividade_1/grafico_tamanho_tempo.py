import matplotlib.pyplot as plt
import pandas as pd

dados_tempos = {
    'Tamanho do Vetor': [
        1000, 5000, 10000, 50000, 100000, # Bubble Sort
        1000, 5000, 10000, 50000, 100000, # Insertion Sort
        1000, 5000, 10000, 50000, 100000, # Merge Sort
        1000, 5000, 10000, 50000, 100000, # Quick Sort
        1000, 5000, 10000, 50000, 100000, # Selection Sort
        1000, 5000, 10000, 50000, 100000  # Shell Sort
    ],
    'Algoritmo': [
        'Bubble Sort'] * 5 + ['Insertion Sort'] * 5 + ['Merge Sort'] * 5 +
        ['Quick Sort'] * 5 + ['Selection Sort'] * 5 + ['Shell Sort'] * 5,
    'Tempo de Execução (s)': [
        0.001, 0.023, 0.094, 4.011, 19.176, # Bubble Sort
        0.001, 0.009, 0.035, 0.863, 3.461, # Insertion Sort
        0.001, 0.003, 0.005, 0.045, 0.157, # Merge Sort
        0.000, 0.001, 0.001, 0.004, 0.009, # Quick Sort
        0.001, 0.014, 0.053, 1.296, 5.147, # Selection Sort
        0.000, 0.000, 0.001, 0.007, 0.017  # Shell Sort
    ]
}

df = pd.DataFrame(dados_tempos)

plt.figure(figsize=(12, 8))

for algoritmo in df['Algoritmo'].unique():
    subset = df[df['Algoritmo'] == algoritmo]
    plt.plot(subset['Tamanho do Vetor'], subset['Tempo de Execução (s)'], label=algoritmo, marker='o')

plt.xlabel('TAMANHO DO VETOR')
plt.ylabel('TEMPO DE EXECUÇÃO (S)')
plt.title('COMPARAÇÃO DE TEMPO DE EXECUÇÃO X TAMANHO DO VETOR')
plt.legend(title='Algoritmos')
plt.grid(True, linestyle='--', alpha=0.6)

plt.tight_layout()
plt.savefig('comparacao_algoritmos_linha.png')

print("Gráfico gerado! O arquivo 'comparacao_algoritmos_linha.png' está salvo.")