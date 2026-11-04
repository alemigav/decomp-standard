/* FUN_80165bb4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165bb4  body 0x80165bb4..0x80165c5b  size 168 B
 * body sha256 a7775842d7982ae583b861038623da012a6a77e9eaef5102dc0eeede71cd0423
 * provider record sha256 d759b660f4021d5fe824a0391055887cc78546b65e4b0def56443bf4bae8f7bb
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165bb4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 700) == '\0') {
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500));
    FUN_8016655c(param_1,10,0);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,(int)*(short *)(param_1 + 0x1f6));
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 7) == '\0') {
      *(undefined1 *)(param_1 + 7) = 1;
      *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x1ea) * 0x100 + 0x12000000;
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0x7000000;
    }
  }
  return;
}
