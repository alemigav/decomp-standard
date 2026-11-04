/* FUN_800924bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800924bc  body 0x800924bc..0x80092607  size 300 B
 * body sha256 107f0d3d7447eda2820b22078f8a7b38201964b712f6b81bb2331fb1f984cf54
 * provider record sha256 a90f12a00bfdf659a5d9e94102e76c0efd7ba2c76e90011a85864fe6a394b5b4
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800924bc(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  DAT_8012bf98 = 1;
  DAT_8012bfc1 = 1;
  DAT_8012bf99 = 2;
  DAT_8012bff0 = 0;
  DAT_8012bff2 = 0;
  DAT_8012bfc0 = 10;
  switch(DAT_8012f522) {
  case 0:
    DAT_8012bfb2 = 5;
    break;
  case 1:
  case 4:
    DAT_8012bfb2 = 3;
    break;
  case 2:
    DAT_8012bfb2 = 5;
    break;
  case 3:
    DAT_8012bfb2 = 0x10;
  }
  FUN_800479c8(DAT_800c52dc + 0x44807U & 0xfffffff8,&DAT_8012f5a0,
               *(undefined2 *)
                (&DAT_8012f8ec + (uint)*(ushort *)(&DAT_80130cba + (uint)DAT_8012bfb2 * 8) * 2));
  uVar2 = 0x100;
  uVar3 = 0x100;
  FUN_80090e10();
  FUN_800274f8(0x200,0xffffe800,7,1,uVar2,uVar3);
  do {
    FUN_8004cd88(1);
    FUN_80097fd0();
    FUN_8009202c();
    iVar1 = FUN_8002767c(0);
  } while (iVar1 == 0);
  FUN_80077adc(0x4090000,0);
  FUN_8006c070(1);
  return;
}
