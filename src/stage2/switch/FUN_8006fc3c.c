/* FUN_8006fc3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fc3c  body 0x8006fc3c..0x8006fc5b  size 32 B
 * body sha256 ef5e2b5bdbc58afdcb24b737c60b82c62e2c8fcc75bfcfdcc5a124567d3884a3
 * provider record sha256 29e1692e3c8ba0e4e2b5658c2084e3f1e6068200a16a2a377957b9937e71e880
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8006fb9c::caseD_5(undefined4 param_1,int param_2,int param_3)

{
  *(undefined4 *)(param_3 + 0x154) = (&DAT_80132118)[param_2];
  return 1;
}
