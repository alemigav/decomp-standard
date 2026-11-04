/* FUN_800717a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800717a0  body 0x800717a0..0x8007194f  size 256 B
 * body sha256 448870013cc6f8638a2fcce86e4de66102ac87209b9c84c96fb37a26fe9b521b
 * provider record sha256 c43818cb9e47eadd753599715b87dea9ba0087463b0126c0e03ed2ba6dc67ba1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_800717a0(uint param_1,byte param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  if (((int)(char)param_1 & 0x80U) == 0) {
    switch((char)param_1) {
    case '\0':
      return &DAT_800e9028;
    case '\x01':
      return (undefined4 *)0x14;
    case '\x02':
      return (undefined4 *)(DAT_800e13ec + 0x14);
    case '\x03':
      return (undefined4 *)
             (*(int *)((int)&DAT_800e13f0 + ((int)((uint)param_2 << 0x18) >> 0x16)) + 0x14);
    case '\x04':
      return (undefined4 *)(&DAT_800e193c + (char)param_2 * 0x368);
    default:
      return (undefined4 *)0x0;
    }
  }
  uVar2 = (param_1 & 0x60) >> 5;
  iVar3 = DAT_800e13ec;
  if (uVar2 != 1) {
    iVar3 = param_3;
    if (uVar2 < 2) {
      if (uVar2 != 0) goto LAB_8007192c;
      puVar1 = &DAT_800df6b0;
    }
    else {
      if (uVar2 != 2) goto LAB_8007192c;
      puVar1 = &UNK_800df6b8 + ((int)((uint)param_2 << 0x18) >> 0x16);
    }
    iVar3 = *(int *)(puVar1 + 0x1d38);
  }
LAB_8007192c:
  return (undefined4 *)(*(int *)(iVar3 + 0x234) + (param_1 & 0x1f) * 0x178 + 0x38);
}
