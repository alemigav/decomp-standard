/* FUN_8007dd40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dd40  body 0x8007dd40..0x8007ddbf  size 128 B
 * body sha256 5b624e809d0f5660d3efcbb9b57360e12796b15662f97d84a36b81d356a54428
 * provider record sha256 262f1817631f6deff9319be78c99108cb0548be3e2ed1cc6f8bad0de49d9791e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007dd40(int param_1)

{
  if ((*(ushort *)(param_1 + 0x2b8) & 0x4000) == 0) {
    *(undefined2 *)(param_1 + 6) = 0x300;
  }
  else if (((*(ushort *)(param_1 + 0x1f0) & 0xa000) == 0) || (*(char *)(param_1 + 0x1ea) == '\0')) {
    (*(code *)(&PTR_LAB_8011b2a4)
              [*(byte *)((int)&PTR_LAB_8011b210 + (uint)*(byte *)(*(int *)(param_1 + 0x250) + 8))])
              (param_1,*(undefined2 *)(param_1 + 0x1aa));
  }
  return;
}
