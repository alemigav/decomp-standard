/* FUN_8005906c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005906c  body 0x8005906c..0x80059093  size 40 B
 * body sha256 6780a945cc2b8bbf700b3c6b7a197e0b5d7c4106065d9918d676f5971724bff8
 * provider record sha256 3178488b739f3e9e0c4aaa3963a9f7b098df0b3095f6d71338384e4f664d9040
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_7(void)

{
  int unaff_s0;
  
  FUN_800551e0();
  *(undefined4 *)(unaff_s0 + 4) = 0x1000000;
  return;
}
