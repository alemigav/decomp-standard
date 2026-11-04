/* FUN_80167a60
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80167a60  body 0x80167a60..0x80167b1b  size 188 B
 * body sha256 22d82d8216dc7c87a6ae9f89a10f777cca3af94cf41259af4e500e03cb756f30
 * provider record sha256 5d646d18fda7ab274edbe27b49e30fb683f8c8ee86c0e1ccfe9a725d111206b3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167a60(int param_1)

{
  byte bVar2;
  uint uVar1;
  uint uVar3;
  
  bVar2 = *(char *)(param_1 + 0x2d7) - 1;
  if (*(char *)(param_1 + 0x2d7) != '\0') {
    *(byte *)(param_1 + 0x2d7) = bVar2;
    uVar3 = 0;
    if ((bVar2 & 1) != 0) {
      do {
        uVar1 = func_0x80033604();
        if ((*(uint *)(*(int *)(param_1 + 0x234) + (uint)(byte)(&DAT_8016803c)[uVar1 & 7] * 0x178) &
            0x4b) == 1) {
          FUN_8016703c(param_1,(uint)(byte)(&DAT_8016803c)[uVar1 & 7],9);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 3);
    }
  }
  return;
}
