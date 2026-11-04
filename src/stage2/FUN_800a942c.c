/* FUN_800a942c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a942c  body 0x800a942c..0x800a949b  size 112 B
 * body sha256 e0f04b1aeb6e17edbc7e5f38a6f76c9250441c8b66bfdfa9145be3bb79fdcbda
 * provider record sha256 59ac655b03b1093a02e090143a58911701ae9e2b5644be415b43370e4e6fdbb0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a942c(int param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    if ((&DAT_801481e0)[param_1 * 0x18] == '\x01') {
      (&DAT_801481e0)[param_1 * 0x18] = '\0';
      FUN_800af130(param_1);
    }
    FUN_800a56c0();
  }
  return;
}
