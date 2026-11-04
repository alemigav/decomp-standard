/* FUN_8006d998
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d998  body 0x8006d998..0x8006da13  size 124 B
 * body sha256 8a392524f68de9b9b2f046215d443f5e2ea54f4810ebf504b449e07bbd14513f
 * provider record sha256 2cbd3687084f8747aec150cdc86c24b6d652f1330b0c1c6f2755c1712bcb5705
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d998(void)

{
  FUN_8006d890();
  if ((DAT_800e1110 & 0x2000000) == 0) {
    FUN_8006d284();
    DAT_80114f34 = 0;
    DAT_80114f2c = *(undefined4 *)(DAT_800df92c + 0x4c);
    FUN_8006d628(0,1);
    FUN_8006da14();
  }
  return;
}
