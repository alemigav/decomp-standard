/* FUN_8016882c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016882c  body 0x8016882c..0x80168983  size 344 B
 * body sha256 41a475b5facd00a382fd3e92764280577bd3ee49673a2ac4aad96a5aa50bcab9
 * provider record sha256 ab1649ec5b18ee170cb60b02468268321563ce1b1b4650752c0e943864ce8990
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016882c(int param_1,int param_2)

{
  byte bVar1;
  
  if (*(char *)(param_1 + 0x2bd) == '\0') {
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) + 0x400;
    if (0x1000 < *(short *)(*(int *)(param_2 + 0x120) + 0x10)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x10) = 0x1000;
      *(undefined1 *)(param_1 + 0x2bd) = 1;
      *(undefined2 *)(param_1 + 0x2be) = 0;
      bVar1 = func_0x80033604(param_1);
      DAT_80168f4f = '\x0e' - bVar1 % 0x1c;
      bVar1 = func_0x80033604();
      DAT_80168f4e = '\x0e' - bVar1 % 0x1c;
    }
  }
  else if (*(char *)(param_1 + 0x2bd) == '\x01') {
    *(short *)(*(int *)(param_2 + 0x120) + 0x10) =
         *(short *)(*(int *)(param_2 + 0x120) + 0x10) - *(short *)(param_1 + 0x2be);
    *(short *)(param_1 + 0x2be) = *(short *)(param_1 + 0x2be) + 100;
    if (*(short *)(*(int *)(param_2 + 0x120) + 0x10) < 0) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0x10) = 0;
      *(undefined1 *)(param_1 + 700) = 0;
      *(undefined1 *)(param_1 + 0x2bd) = 0;
      DAT_80168f4f = '\0';
      DAT_80168f4e = '\0';
    }
  }
  func_0x80066288(param_1,param_2);
  return;
}
