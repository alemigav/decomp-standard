/* FUN_800aa6b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa6b8  body 0x800aa6b8..0x800aa83b  size 388 B
 * body sha256 a3ca909d722c70ce1d5a86d9f112976f0743efe53bf3abfee55fab76e3ae66bc
 * provider record sha256 210e8944e633d6173184067a1ebd5100b039a46655fff24e55ec66c4106f464c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800aa6b8(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 float *param_5,byte param_6)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  bVar1 = DAT_80136310 != '\0';
  if (bVar1) {
    FUN_800a5678();
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    *(undefined4 *)(param_1 + 0xc) = *param_2;
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    *(undefined4 *)(param_1 + 0x14) = uVar3;
    uVar2 = param_3[1];
    uVar3 = param_3[2];
    *(undefined4 *)(param_1 + 0x18) = *param_3;
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    *(undefined4 *)(param_1 + 0x20) = uVar3;
    uVar2 = param_4[1];
    uVar3 = param_4[2];
    *(undefined4 *)(param_1 + 0x24) = *param_4;
    *(undefined4 *)(param_1 + 0x28) = uVar2;
    *(undefined4 *)(param_1 + 0x2c) = uVar3;
    *(float *)(param_1 + 0x3c) = -*param_5;
    *(float *)(param_1 + 0x40) = -param_5[1];
    *(float *)(param_1 + 0x44) = -param_5[2];
    FUN_800ab2cc(param_1 + 0x30,param_1 + 0x3c,param_1 + 0x24);
    local_50 = *(undefined4 *)(param_1 + 0x30);
    local_44 = *(undefined4 *)(param_1 + 0x34);
    local_38 = *(undefined4 *)(param_1 + 0x38);
    local_4c = *(undefined4 *)(param_1 + 0x3c);
    local_40 = *(undefined4 *)(param_1 + 0x40);
    local_34 = *(undefined4 *)(param_1 + 0x44);
    local_48 = *(undefined4 *)(param_1 + 0x24);
    local_3c = *(undefined4 *)(param_1 + 0x28);
    local_30 = *(undefined4 *)(param_1 + 0x2c);
    local_2c = *(undefined4 *)(param_1 + 0xc);
    local_28 = *(undefined4 *)(param_1 + 0x10);
    local_24 = *(undefined4 *)(param_1 + 0x14);
    FUN_800aaf90(param_1 + 0x48,&local_50);
    *(float *)(param_1 + 0x84) = (float)param_6 / 127.0;
    FUN_800a56c0();
  }
  return bVar1;
}
