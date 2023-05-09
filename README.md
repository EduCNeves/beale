# beale
  
Compilação:
    
    $ make

Formas de executar:

- Codificar uma mensagem qualquer contida em um arquivo ASCII usando um livro cifra:
    
      $ ./beale -e -b "LivroCifra" -m "MensagemOriginal" -o "MensagemCodificada" -c "ArquivoDeChaves"
    
- Decodificar uma mensagem, usando um arquivo de códigos:
    
      $ make ./beale -d -i "MensagemCodificada"  -c "ArquivoDeChaves" -o "MensagemDecodificada"

- Decodificar uma mensagem usando o livro cifra:
    
      $ ./beale -d -i "MensagemCodificada" -b "LivroCifra" -o "MensagemDecodificada"
