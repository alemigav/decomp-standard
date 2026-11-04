/* FUN_8005ef08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ef08  body 0x8005ef08..0x8005efc3  size 188 B
 * body sha256 f8ca6bdcc02bdc9b851eedb56279c04aa326db33778f24e4d263daae25f7b5c2
 * provider record sha256 833c854b1c743b8219129534341158a0c00577b9cf992821566fc7dab63a74dc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ef08(int param_1)

{
  int iVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  if (*(char *)(param_1 + 0x1e9) == '\x01') {
    local_18 = 0;
    local_16 = 0x44c;
    local_14 = 0;
    iVar1 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1002000,0,iVar1,&local_18);
    FUN_80037780(0x20d1000,(int)*(short *)(param_1 + 0x66),iVar1,&local_18);
    FUN_80037780(0x30a1a00,0,iVar1,&local_18);
    local_18 = 300;
    local_16 = 0xfc7c;
    FUN_80037780(0x30a1500,0,iVar1,&local_18);
  }
  return;
}
