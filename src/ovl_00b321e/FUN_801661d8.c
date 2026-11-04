/* FUN_801661d8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801661d8  body 0x801661d8..0x8016622b  size 84 B
 * body sha256 4c2e4b46ca6090b6a130e8d4f514c23abba48310d539b57c8142048b4cd34e67
 * provider record sha256 e496886cc3729815a2d0b7b981c4f07ddbedcb5fbb2f5a048484448cd91bc1bb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801661d8(int param_1,char param_2)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &DAT_800e1130;
  }
  else {
    puVar1 = _DAT_800e13ec;
  }
  puVar1[4] = 2;
  puVar1[5] = param_2 + '\x02';
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[0x26f] = puVar1[0x26f] | 0x80;
  return;
}
