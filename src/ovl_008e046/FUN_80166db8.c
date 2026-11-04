/* FUN_80166db8
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166db8  body 0x80166db8..0x80166e8b  size 212 B
 * body sha256 0b606c011bf36337283bf9041ec510c589beefe9542fb42e4186781455794fc9
 * provider record sha256 a846bc3ec3c76e612d02812b3c569e0d79ecd029e01c70192097d28686c57987
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166db8(int param_1,int param_2,int param_3,uint param_4,short param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  short local_20;
  short local_1e;
  short local_1c;
  
  iVar1 = *(int *)(param_1 + 0x234) + param_6 * 0x178;
  func_0x8004276c(iVar1 + 0x38,param_7,&local_20);
  local_20 = local_20 + *(short *)(iVar1 + 0x4e);
  local_1e = local_1e + *(short *)(iVar1 + 0x52);
  local_1c = local_1c + *(short *)(iVar1 + 0x56);
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(int)param_5,&DAT_800e9028,&local_20);
  return;
}
