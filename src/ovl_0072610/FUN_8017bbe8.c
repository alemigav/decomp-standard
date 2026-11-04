/* FUN_8017bbe8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017bbe8  body 0x8017bbe8..0x8017bd8b  size 420 B
 * body sha256 ac614dcba3c9ac977ff892977a2c37e47f3fed9e1e9ff93ad31f9275c98f0ee4
 * provider record sha256 f10fd36acbdf024a2ca58a9b54bd567ba6899d8207a4b4eed860a26050aea871
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017bc38) */
/* WARNING: Removing unreachable block (ram,0x8017bc50) */
/* WARNING: Removing unreachable block (ram,0x8017bc58) */
/* WARNING: Removing unreachable block (ram,0x8017bc70) */
/* WARNING: Removing unreachable block (ram,0x8017bc78) */
/* WARNING: Removing unreachable block (ram,0x8017bca4) */

void FUN_8017bbe8(uint param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  piVar2 = DAT_80186c94;
  iVar3 = DAT_80186c94[4] - param_1;
  DAT_80186c94[3] = DAT_80186c94[3] << (param_1 & 0x1f);
  piVar2[4] = iVar3;
  piVar2 = DAT_80186c94;
  if (iVar3 < 0x19) {
    if ((uint)DAT_80186c94[2] < *DAT_80186c94 + 0x7fcU) {
      do {
        uVar4 = 0x18 - iVar3;
        iVar3 = iVar3 + 8;
        bVar1 = *(byte *)piVar2[2];
        piVar2[2] = (int)((byte *)piVar2[2] + 1);
        piVar2[3] = piVar2[3] | (uint)bVar1 << (uVar4 & 0x1f);
      } while (iVar3 < 0x19);
    }
    else {
      do {
        if (*DAT_80186c94 + 0x800U <= (uint)DAT_80186c94[2]) {
          FUN_8017b7e8();
        }
        piVar2 = DAT_80186c94;
        uVar4 = 0x18 - iVar3;
        iVar3 = iVar3 + 8;
        bVar1 = *(byte *)DAT_80186c94[2];
        DAT_80186c94[2] = (int)((byte *)DAT_80186c94[2] + 1);
        piVar2[3] = piVar2[3] | (uint)bVar1 << (uVar4 & 0x1f);
      } while (iVar3 < 0x19);
    }
    DAT_80186c94[4] = iVar3;
  }
  return;
}
