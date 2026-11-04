/* FUN_80052f10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052f10  body 0x80052f10..0x80052f3b  size 44 B
 * body sha256 def045116cc524c42c47c36281b16488ee6fc6858264f9abe0c37f5348cc3cf7
 * provider record sha256 b46f20ff52e9948a84dcbf599d2108152cbf3671817a99b5e100407e10559187
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80052f10(char *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  do {
    if (*param_1 != '\0') {
      iVar2 = iVar2 + 1;
    }
    uVar1 = uVar1 + 1;
    param_1 = param_1 + 10;
  } while (uVar1 < 0x20);
  return iVar2;
}
