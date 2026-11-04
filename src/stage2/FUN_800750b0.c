/* FUN_800750b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800750b0  body 0x800750b0..0x8007513f  size 144 B
 * body sha256 fdf7615b3eb0fbaf807ae4bdd5e5c67b51165f9115652a6d52d493b3a0697563
 * provider record sha256 560a386abd37ddb21c891522993d1490954648695439b6c4f5bb698c2345de23
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800750b0(short param_1)

{
  if (param_1 != 0) {
    DAT_8011a28f = DAT_80119e73;
  }
  FUN_800b2098((int)((uint)DAT_80119e73 * (uint)DAT_80119e7c) >> 7 & 0xff,0,0,1);
  FUN_800b2098((int)((uint)DAT_80119e74 * (uint)DAT_80119e7c) >> 7 & 0xff,0,1,0);
  return;
}
