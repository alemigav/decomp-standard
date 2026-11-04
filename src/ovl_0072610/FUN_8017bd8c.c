/* FUN_8017bd8c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017bd8c  body 0x8017bd8c..0x8017bec7  size 316 B
 * body sha256 c6bf1529fd3eed0f2b6659fcc478cc7bb932da646a80b396e5bf93d20a78df4e
 * provider record sha256 911d1f311531993e3dda34ca420bbb3a5377cc5e77aaa75d4f60203c3ae44f1e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017bdc0) */
/* WARNING: Removing unreachable block (ram,0x8017bdd8) */
/* WARNING: Removing unreachable block (ram,0x8017bde0) */
/* WARNING: Removing unreachable block (ram,0x8017bde4) */
/* WARNING: Removing unreachable block (ram,0x8017bdfc) */
/* WARNING: Removing unreachable block (ram,0x8017be04) */
/* WARNING: Removing unreachable block (ram,0x8017be30) */

void FUN_8017bd8c(void)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  
  piVar1 = DAT_80186c94 + 4;
  DAT_80186c94[3] = 0;
  for (iVar3 = *piVar1 + -0x20; iVar3 < 0x19; iVar3 = iVar3 + 8) {
    if (*DAT_80186c94 + 0x800U <= (uint)DAT_80186c94[2]) {
      FUN_8017b7e8();
    }
    piVar1 = DAT_80186c94;
    bVar2 = *(byte *)DAT_80186c94[2];
    DAT_80186c94[2] = (int)((byte *)DAT_80186c94[2] + 1);
    piVar1[3] = piVar1[3] | (uint)bVar2 << (0x18U - iVar3 & 0x1f);
  }
  DAT_80186c94[4] = iVar3;
  return;
}
