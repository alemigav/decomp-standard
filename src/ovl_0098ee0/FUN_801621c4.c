/* FUN_801621c4
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801621c4  body 0x801621c4..0x80162227  size 100 B
 * body sha256 7efd1febed1bac17adb1265294ef9af9cd8e24276cd28575d24862b1cd0da600
 * provider record sha256 79d805916b8eadfe715f28c7b076c3f0520dcad41069fd8d2b0130299135beaa
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_801621c4(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  uVar2 = sVar1 - *(short *)(param_1 + 0x66) & 0xfff;
  if (0x800 < uVar2) {
    uVar2 = uVar2 | 0xf000;
  }
  return (int)(short)uVar2;
}
