/* FUN_80168984
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80168984  body 0x80168984..0x80168b3b  size 440 B
 * body sha256 a473e7f755e1dbd0c2a181e8430e9beff897e2cd4c0d6f3f3f2759b992506a52
 * provider record sha256 97e024f6d3c98943878b6183fc95be55ce68208fec41b167738dde6a0f45ed0b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168984(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x2bd);
  if (bVar2 == 1) {
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) + -500;
    cVar1 = *(char *)(param_1 + 699) + -1;
    *(char *)(param_1 + 699) = cVar1;
    *(short *)(param_1 + 0x2be) = *(short *)(param_1 + 0x2be) + 100;
    if (cVar1 == -1) {
      *(undefined1 *)(param_1 + 699) = 3;
      *(undefined1 *)(param_1 + 0x2bd) = 2;
    }
  }
  else if (bVar2 < 2) {
    if (bVar2 == 0) {
      *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
           *(short *)(*(int *)(param_2 + 0x120) + 0x10) + 0x400;
      if (0xc00 < *(short *)(*(int *)(param_2 + 0x120) + 0x10)) {
        *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x10) = 0xc00;
        *(undefined1 *)(param_1 + 0x2bd) = 1;
        *(undefined2 *)(param_1 + 0x2be) = 0;
        *(undefined1 *)(param_1 + 699) = 3;
      }
    }
  }
  else if (bVar2 == 2) {
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) + 500;
    cVar1 = *(char *)(param_1 + 699) + -1;
    *(char *)(param_1 + 699) = cVar1;
    *(short *)(param_1 + 0x2be) = *(short *)(param_1 + 0x2be) + -100;
    if (cVar1 == -1) {
      *(undefined1 *)(param_1 + 699) = 3;
      *(undefined1 *)(param_1 + 0x2bd) = 1;
    }
  }
  bVar2 = func_0x80033604();
  DAT_80168f4f = '\x0e' - bVar2 % 0x1c;
  bVar2 = func_0x80033604();
  DAT_80168f4e = '\x0e' - bVar2 % 0x1c;
  func_0x80066288(param_1,param_2);
  return;
}
