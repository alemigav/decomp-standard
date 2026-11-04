/* FUN_8005925c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005925c  body 0x8005925c..0x800592b7  size 92 B
 * body sha256 85d8128ae7c35c135717ed08170de0c515ed4d9fe97917faf0261247ddbef52d
 * provider record sha256 b4efb3f57f9c9e99d167b985a2773c6e5fe855c20afe8046e12254af9de85c10
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005925c(int param_1)

{
  DAT_800e110c = DAT_800e110c | 0x40;
  (*(code *)(&PTR_FUN_8010dce8)[*(byte *)(param_1 + 5)])
            (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
  return;
}
