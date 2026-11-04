/* FUN_8003b14c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b14c  body 0x8003b14c..0x8003b1b7  size 108 B
 * body sha256 03646e019008fa1a1831787e6c75dda53eafbbbc822e715b94d6b6505552462a
 * provider record sha256 386dca9c316ad3b1a19d9ea74f735b7a89d7f7434b266ac05091851538b92022
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b14c(void)

{
  undefined1 *puVar1;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
  FUN_80069f1c(&local_18,2,0x2000,0);
  puVar1 = DAT_800ebb94;
  if (DAT_8011270c != 0) {
    *DAT_800ebb94 = 0;
    *(undefined2 *)(puVar1 + 0x18) = 0;
  }
  return;
}
