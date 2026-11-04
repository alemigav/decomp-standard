/* FUN_801663a4
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801663a4  body 0x801663a4..0x801664af  size 268 B
 * body sha256 a213d68cce7d582094291990ef288f554c4e894f7e6a69366283f12350b71be3
 * provider record sha256 e76341ed59827ba644d6d819f6bc732cb6b9bca18f744a4fdbd8d5bfb6d9d365
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801663a4(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  param_3 = param_3 * 8;
  iVar1 = (param_2 & 0x7f) * 6;
  iVar2 = *(int *)(param_1 + 0x234) + *(short *)(&DAT_801668ac + param_3) * 0x178;
  if ((param_2 & 0x80) == 0) {
    local_18 = *(undefined2 *)(&DAT_801668ae + param_3);
    local_16 = *(undefined2 *)(&DAT_801668b0 + param_3);
    local_14 = *(undefined2 *)(&DAT_801668b2 + param_3);
    func_0x80037780(((byte)(&DAT_80166858)[iVar1] & 0x7f) << 0x18 |
                    ((uint)(byte)(&DAT_80166859)[iVar1] + (uint)*(ushort *)(&DAT_8016685a + iVar1))
                    * 0x10000 | (uint)*(ushort *)(&DAT_8016685c + iVar1),
                    (int)*(short *)(param_1 + 0x66),iVar2 + 0x38,&local_18);
  }
  else {
    local_18 = *(undefined2 *)(iVar2 + 0x4e);
    local_16 = *(undefined2 *)(param_1 + 0x25e);
    local_14 = *(undefined2 *)(iVar2 + 0x56);
    local_10 = *(undefined2 *)(&DAT_801668ae + param_3);
    local_e = 0;
    local_c = *(undefined2 *)(&DAT_801668b2 + param_3);
    FUN_801664b0(param_1,param_2 & 0x7f,&local_18,&local_10);
  }
  return;
}
