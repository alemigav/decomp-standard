/* FUN_80074f70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074f70  body 0x80074f70..0x80074fbb  size 76 B
 * body sha256 0c98bbd04bca6c1b664754795f5f07596b4ba64d9f2a521d19a71ebe79b47baf
 * provider record sha256 f11cee7a6905f567b3eae60109a5b5683509a871b0e1d1de8184cdd14812fa1b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80074f70(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (((DAT_800e110c & 8) != 0) || (uVar1 = 2, (DAT_800e110c & 4) != 0)) {
    FUN_80074fbc(uVar1);
  }
  return;
}
