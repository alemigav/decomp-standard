/* FUN_80164d88
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164d88  body 0x80164d88..0x80164deb  size 100 B
 * body sha256 2ec6608f03481e49eaad03964548ba497797492e070612673f72676e5c135966
 * provider record sha256 7c56dfd42a5d29aeb0b38a0b5ead201814a355e0d065238dfdd402d230d7476a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164d88(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 7) == '\0') {
    cVar1 = func_0x80036c68(param_1,5,0xf,0);
    *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar1;
  }
  else if (*(char *)(param_1 + 7) == '\x01') {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
