/* FUN_8016bdc4
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016bdc4  body 0x8016bdc4..0x8016bf67  size 420 B
 * body sha256 6fe7dd048fec13deb68c85dc4ac1291f2e77ec7e5cf08cf904d70ee3a4355784
 * provider record sha256 8f0b2d4fe2c094145d3253860711f7aea497ea5ca77966cc9c692352984200de
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016bdc4(int param_1,undefined2 *param_2,undefined2 param_3,short param_4)

{
  int iVar1;
  int iVar2;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  undefined1 auStack_50 [32];
  undefined4 local_30;
  undefined4 local_28;
  
  local_56 = func_0x80032d14((int)_DAT_800e115a,(int)_DAT_800e1162,(int)*(short *)(param_1 + 0x2a),
                             (int)*(short *)(param_1 + 0x32));
  local_58 = 0;
  local_54 = 0;
  func_0x80040e58(&local_58,auStack_50);
  local_56 = 0;
  local_58 = param_3;
  func_0x80042824(auStack_50,&local_58,&local_30);
  local_30 = local_30 + _DAT_800e1158;
  local_28 = local_28 + _DAT_800e1160;
  if (param_4 != 0) {
    iVar1 = func_0x800667d4(&local_30,0x578,1,0x500);
    iVar2 = 0;
    if (iVar1 != 0) {
      do {
        iVar1 = (iVar2 << 0x10) >> 0xe;
        local_30 = _DAT_800e1158 + *(short *)((int)&DAT_8016c28c + iVar1);
        local_28 = _DAT_800e1160 + *(short *)((int)&DAT_8016c28e + iVar1);
        iVar1 = func_0x800667d4(&local_30,0x578,1,0x500);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) break;
      } while (iVar2 * 0x10000 >> 0x10 < 9);
    }
  }
  iVar1 = local_30 - *(int *)(param_1 + 0x28);
  iVar2 = local_28 - *(int *)(param_1 + 0x30);
  *param_2 = local_30._2_2_;
  param_2[2] = local_28._2_2_;
  func_0x80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
  return;
}
