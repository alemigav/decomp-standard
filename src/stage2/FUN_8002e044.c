/* FUN_8002e044
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e044  body 0x8002e044..0x8002e0a7  size 100 B
 * body sha256 2ca7a164972792e0b475e0e48c25fbc0e4c487f9b2539e485cac714034b2cd5e
 * provider record sha256 0c4cb498060f0029c72ff446244af490eef8fc268ce9b8d997c1ab41ce3fb446
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e044(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6)

{
  (**(code **)(*(int *)(param_1 + 0x180) + 0xc))(param_1,param_2,*param_3,param_5 + *param_6 * 4);
  *param_6 = *param_6 + 1;
  *param_3 = *param_3 + 1;
  return;
}
