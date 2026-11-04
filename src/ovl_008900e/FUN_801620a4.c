/* FUN_801620a4
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801620a4  body 0x801620a4..0x801621c3  size 288 B
 * body sha256 e852fe87843df669c79fa7ac44eb15191c82fffdf99406f9156c20da63c97fad
 * provider record sha256 cf91acbcc2f7c9dc3fbcf8a012de78cd9d20fa5017c7e918b8be5847fcc1976f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801620a4(uint *param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0x898f963;
  local_c = 0;
  func_0x8008383c((int)*(short *)((int)param_1 + 0x66),param_1[0x1c],&local_10,&local_10);
  param_1[10] = (int)*(short *)(param_1 + 0xb4) + (int)local_10._0_2_;
  param_1[0xb] = param_1[0xb] + (int)local_10._2_2_;
  param_1[0xc] = (int)*(short *)(param_1 + 0xb5) + (int)local_c._0_2_;
  iVar1 = func_0x8006a7ec(param_1[0x1c]);
  iVar1 = iVar1 * 0x18;
  DAT_80168d58 = *(undefined2 *)(&DAT_801689c0 + (uint)*(byte *)(param_1 + 0xad) * 6 + iVar1);
  DAT_80168d5a = *(undefined2 *)(&DAT_801689c2 + (uint)*(byte *)(param_1 + 0xad) * 6 + iVar1);
  DAT_80168d5c = *(undefined2 *)(&DAT_801689c4 + (uint)*(byte *)(param_1 + 0xad) * 6 + iVar1);
  *param_1 = *param_1 & 0xfffffff7;
  return;
}
