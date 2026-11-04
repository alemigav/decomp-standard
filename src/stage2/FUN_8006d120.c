/* FUN_8006d120
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d120  body 0x8006d120..0x8006d283  size 356 B
 * body sha256 88cec7cebd3620dca98df3549b1afdccae5fd99f670bf2a87c087f608f94900a
 * provider record sha256 471c6db26d61c81e8bc3ff91d4508a821502e583eb7c924df87ed34aeea01e85
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006d120(void)

{
  bool bVar1;
  char *pcVar2;
  uint *puVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  bVar1 = false;
  if ((_DAT_80114f3c & 0xffff0000) != 0) {
    pcVar4 = "\x03";
    DAT_800e861f = '\0';
    pcVar2 = "";
    do {
      if ((*pcVar4 == DAT_80114f3c) && ((DAT_80114f3d == '\0' || (DAT_80114f3d == *pcVar2)))) {
LAB_8006d1e4:
        puVar6 = &DAT_800e13ec;
        if (DAT_800df93c != &DAT_800e13ec) {
          do {
            puVar3 = (uint *)*puVar6;
            uVar5 = *puVar3;
            if ((uVar5 & 1) != 0) {
              if ((int)*(char *)((int)puVar3 + 0x296) == _DAT_80114f3c >> 0x18) {
                if (bVar1) {
                  *puVar3 = uVar5 | 0x2000;
                }
              }
              else if (((int)*(char *)((int)puVar3 + 0x296) == (_DAT_80114f3c >> 0x10 & 0xff)) &&
                      (!bVar1)) {
                *puVar3 = uVar5 | 0x2000;
              }
            }
            puVar6 = puVar6 + 1;
          } while (puVar6 != DAT_800df93c);
        }
        return;
      }
      if ((*pcVar2 == DAT_80114f3c) && ((DAT_80114f3d == '\0' || (DAT_80114f3d == *pcVar4)))) {
        bVar1 = true;
        goto LAB_8006d1e4;
      }
      pcVar2 = pcVar2 + 2;
      pcVar4 = pcVar4 + 2;
      DAT_800e861f = DAT_800e861f + '\x01';
    } while (*pcVar4 != -1);
  }
  DAT_800e861f = 0xff;
  return;
}
