/* FUN_80073cf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073cf8  body 0x80073cf8..0x80073e37  size 320 B
 * body sha256 1b0f739dbcf39621b395f541daf4fa6c934e5a95719109940ac8682c3c25fd91
 * provider record sha256 037b2315664d78388400d78b67ef1f70af3ff054e2cad0d648e125eb449e7310
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80073cf8(void)

{
  char cVar1;
  
  if (DAT_800e861d == 0) {
    if ((DAT_8010b294 & 0x80) == 0) {
      if ((DAT_8010b294 & 1) == 0) {
        (&DAT_800e8ec8)[_DAT_8013a120 * 4] = 0;
        (&DAT_800e8eca)[_DAT_8013a120 * 4] = 0;
        FUN_8008c568();
      }
      else {
        (&DAT_800e8ec9)[_DAT_8013a120 * 4] = 1;
      }
      DAT_800e8924 = 0;
    }
  }
  else {
    _DAT_8013a120 = DAT_800e861d - 1;
    if ((DAT_8010b294 & 0x80) == 0) {
      cVar1 = (&DAT_800e8ec9)[_DAT_8013a120 * 4];
      (&DAT_800e8ec9)[_DAT_8013a120 * 4] = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        FUN_8004ac04(0,0x100,9,0xff000000);
        DAT_800e1110 = DAT_800e1110 | 0xff000000;
      }
      else {
        DAT_800e8924 = 0;
      }
      DAT_800e861d = 0;
    }
  }
  return;
}
