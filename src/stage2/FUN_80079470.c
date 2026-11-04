/* FUN_80079470
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079470  body 0x80079470..0x8007955f  size 240 B
 * body sha256 5592effaf2fec290b0979d2f6ac73d8344671fc30859f59b896df1bbeee36432
 * provider record sha256 81d3dce312cd327002bdaf31bc4cf17e37630127bbb2092b1f763366592f4e86
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079470(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_8007ba00();
  if (param_1 == DAT_800e13ec) {
    uVar1 = 0x40000000;
  }
  else {
    uVar1 = 0x20000000;
  }
  if ((DAT_800e1110 & uVar1) == 0) {
    (*(code *)(&PTR_FUN_8011a870)[*(byte *)(param_1 + 4)])
              (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
    FUN_80034280(param_1,(int)*(short *)(param_1 + 0x66));
    (*(code *)(&PTR_LAB_8011a894)[*(byte *)(param_1 + 8) - 0x40])(param_1);
    FUN_8004db5c(param_1);
    if ((*(char *)(param_1 + 8) == 'E') || (*(char *)(param_1 + 8) == 'O')) {
      uVar2 = 0x800;
    }
    else {
      uVar2 = 0x1000;
    }
    FUN_8004dcb8(param_1,uVar2);
  }
  return;
}
