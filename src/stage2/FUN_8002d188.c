/* FUN_8002d188
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d188  body 0x8002d188..0x8002d257  size 208 B
 * body sha256 d8e455379406532fac8c5ed982215f84889e829d9a5a30b4a1c7805471ff159b
 * provider record sha256 29a3d8169c153bc694d6bb5241a3c692b5164169160ab94e6144918dcfc98a9a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002d188(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x174) == 0) {
    uVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x60);
    *(undefined4 *)(param_1 + 0x174) = uVar1;
  }
  iVar3 = 0;
  **(undefined4 **)(param_1 + 0x174) = FUN_8002d164;
  *(code **)(*(int *)(param_1 + 0x174) + 4) = FUN_8002cc54;
  *(code **)(*(int *)(param_1 + 0x174) + 8) = FUN_8002cf20;
  *(code **)(*(int *)(param_1 + 0x174) + 0xc) = FUN_8002c8bc;
  do {
    iVar2 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    *(code **)(*(int *)(param_1 + 0x174) + iVar2 + 0x10) = FUN_8002c8bc;
  } while (iVar3 < 0x10);
  *(code **)(*(int *)(param_1 + 0x174) + 0x10) = FUN_8002b810;
  *(code **)(*(int *)(param_1 + 0x174) + 0x48) = FUN_8002bb40;
  FUN_8002d164();
  return;
}
