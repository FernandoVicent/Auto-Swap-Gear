# Controle de Servo com Botões – Simulação de Troca de Marchas

Este projeto em Arduino simula um sistema de troca de marchas utilizando um servo motor e quatro botões. O objetivo é mover o servo para posições específicas que representam marchas (para cima, para baixo, neutro) somente quando um botão de "engate" está pressionado.

## 📦 Componentes Utilizados

- 1x Arduino (UNO, Nano, etc.)
- 1x Servo motor (ex: SG90)
- 4x Botões
- Resistores de pull-down (ou pull-up, conforme necessário)
- Fios e protoboard

## ⚙️ Funcionalidade

O sistema possui os seguintes controles:

| Botão (Pino)         | Função                 | Posição do Servo |
|----------------------|------------------------|------------------|
| `gear` (9)           | Ativa o sistema        | -                |
| `conditionUp` (12)   | Marcha para cima       | 140°             |
| `conditionDown` (11) | Marcha para baixo      | 30°              |
| `neutral` (10)       | Coloca em neutro       | 60°              |
| Nenhum ativo         | Posição padrão         | 90°              |

⚠️ O servo **só se move** quando o botão `gear` estiver pressionado (nível LOW). Caso contrário, permanece na posição central (90°).

## 🧠 Lógica do Código

1. O servo é inicializado na porta digital 8.
2. Os estados dos botões são lidos a cada ciclo do loop.
3. Se o botão `gear` estiver pressionado:
   - Verifica se o botão de subir ou descer marcha está pressionado.
   - Caso contrário, verifica se o botão de neutro está ativo.
4. Se o botão `gear` **não** estiver pressionado, o servo retorna para 90°.
