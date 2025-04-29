# 📟 Calculadora Simples com Teclado e LCD 16x2

Este é um projeto em desenvolvimento de uma **calculadora simples** feita com **Arduino UNO**, **LCD 16x2** e **teclado matricial (Keypad)**. O sistema permite que o usuário digite uma expressão matemática básica (com números inteiros e operadores `+` e `-`) e visualize o resultado diretamente no display LCD.

🔗 [Simulação do projeto no Wokwi](https://wokwi.com/projects/429597090336184321)

![Projeto no Wokwi](https://wokwi.com/api/project-assets/429597090336184321/screenshot.png)

---

## 🧰 Componentes Utilizados

- Arduino UNO
- LCD 16x2 (I2C)
- Keypad 4x4
- Potencial lógico via código C++
- Protoboard virtual (Wokwi)

---

## 🛠️ Técnica Utilizada

- **Leitura de expressões** diretamente do teclado.
- **Separação de operandos e operadores** em arrays distintos.
- Conversão de caracteres para inteiros com `atoi()`.
- Exibição dinâmica no display com `LiquidCrystal`.
- Lógica de cálculo sequencial (ex: `12+34-5` → `41`).
- Tratamento da tecla `'C'` como **reset** do cálculo.

---

## 🚧 Status do Projeto

**Em desenvolvimento**

- [x] Leitura do teclado
- [x] Exibição da entrada no LCD
- [x] Separação de números e operadores
- [x] Cálculo com `+` e `-`
- [ ] Implementar operadores `*` e `/`
- [ ] Exibir resultado com tecla `=`
- [ ] Tratamento de erros e entradas inválidas
- [ ] Suporte a números negativos

---

## 📁 Organização do Código

- `setup()` → Inicializa o LCD e o teclado.
- `loop()` → Lê entrada do teclado e constrói a expressão e executa o cálculo.

---

## 📷 Screenshot

![Imagem do Projeto no Wokwi](https://wokwi.com/api/project-assets/429597090336184321/screenshot.png)

---

## 📄 Licença

Este projeto é de uso educacional e livre para modificações com atribuição. Sinta-se à vontade para colaborar!

---

## 🤝 Contribuições

Sugestões de melhorias ou correções são bem-vindas! Abra uma issue ou envie um pull request. 🚀
