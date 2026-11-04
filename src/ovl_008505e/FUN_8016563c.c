/* FUN_8016563c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016563c  body 0x8016563c..0x801656eb  size 176 B
 * body sha256 5a3003acab4894223835aa54e835cb2228e0ce5fcd7bf3c9a93ff81954c25815
 * provider record sha256 74aa605f5e22d2c8dca7500ee455106c26478ba821942f98e92ca542b1c17230
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016563c(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  
  if ((*(char *)(param_1 + 0x206) == '\0') &&
     (*(undefined1 *)(param_1 + 0x206) = 1, *(char *)(param_1 + 5) != '\f')) {
    *(undefined2 *)(param_1 + 0x1e0) = 0x28;
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500));
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + ((uVar1 & 0xff) - 0x80);
  }
  FUN_80165030(param_1,param_2,param_3);
  if (1 < *(byte *)(param_1 + 7)) {
    *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) & 0xbf;
  }
  return;
}
