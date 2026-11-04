/* FUN_801664b0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801664b0  body 0x801664b0..0x8016659f  size 240 B
 * body sha256 84877a5e5104a33f67eb72b22d38f91c0bc28e378b7d5eb42b64800338b7d04e
 * provider record sha256 4dbe407033e86de40e57f98e294b0d25514dd75088a9dc530632dd248193f60b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801664b0(int param_1,uint param_2,short *param_3,undefined4 param_4)

{
  int iVar1;
  short local_40;
  short local_3e;
  short local_3c;
  undefined1 auStack_38 [32];
  
  iVar1 = (param_2 & 0x7f) * 6;
  func_0x80040e58(param_1 + 100,auStack_38);
  func_0x8004276c(auStack_38,param_4,&local_40);
  local_40 = local_40 + *param_3;
  local_3e = local_3e + param_3[1];
  local_3c = local_3c + param_3[2];
  func_0x80037780(((byte)(&DAT_80166858)[iVar1] & 0x7f) << 0x18 |
                  ((uint)(byte)(&DAT_80166859)[iVar1] + (uint)*(ushort *)(&DAT_8016685a + iVar1)) *
                  0x10000 | (uint)*(ushort *)(&DAT_8016685c + iVar1),(int)*(short *)(param_1 + 0x66)
                  ,0x800e9028,&local_40);
  return;
}
