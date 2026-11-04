/* FUN_8006a7ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a7ec  body 0x8006a7ec..0x8006a87f  size 148 B
 * body sha256 2ff88d7877df5415abd1b44a677e3d3fce11c1a5ec9410062dee897694164e0b
 * provider record sha256 fe307a52fedcb385aeae820e8baf091af7250c65e5bb3df488523702349765d4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_8006a7ec(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0x7fff;
  local_c = 0;
  FUN_8008383c(0,param_1,&local_10,&local_10);
  uVar1 = local_10._2_2_ < -0x4000;
  if (0x4000 < local_10._0_2_) {
    uVar1 = 2;
  }
  if (local_10._0_2_ < -0x4000) {
    uVar1 = 3;
  }
  if (0x4000 < local_c._0_2_) {
    uVar1 = 4;
  }
  if (local_c._0_2_ < -0x4000) {
    uVar1 = 5;
  }
  return uVar1;
}
